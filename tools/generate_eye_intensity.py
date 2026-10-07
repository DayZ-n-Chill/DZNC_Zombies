"""Builds the eye brightness steps for every per-body glow material.

DayZ can't change emissive at runtime, so each brightness step is its own rvmat:
data/bodies/<body>_<color>_<step>.rvmat. Every step of a body/color is identical
except the emmisive[] line, so any existing step file serves as the template.
Step 5 is the normal brightness; RGB is scaled per step, alpha stays 1.
"""
import pathlib, re, sys
from decimal import Decimal, ROUND_HALF_UP

BASE = {"yellow": (2.5, 2.0, 0), "red": (3.0, 0.1, 0), "blue": (0.2, 0.7, 3.0), "green": (0.3, 2.5, 0.1), "orange": (3.0, 1.2, 0)}
MULTIPLIERS = [0.4, 0.55, 0.7, 0.85, 1.0, 1.25, 1.6, 2.0, 2.75, 3.5]
EMISSIVE = re.compile(r"emmisive\[\]\s*=\s*\{[^}]*\};")
STEP_FILE = re.compile(r"^(.+)_(yellow|red|blue|green|orange)_(\d+)\.rvmat$")


def fmt(value):
    if value == 0:
        return "0"
    d = Decimal(value).quantize(Decimal("0.01"), rounding=ROUND_HALF_UP).normalize()
    text = format(d, "f")
    return text if "." in text else text + ".0"


def emissive(color, mult):
    return "emmisive[]={" + ",".join(fmt(Decimal(str(c)) * Decimal(str(mult))) for c in BASE[color]) + ",1};"


bodies = pathlib.Path(__file__).resolve().parent.parent / "data" / "bodies"
groups = {}
for path in bodies.glob("*.rvmat"):
    m = STEP_FILE.match(path.name)
    if not m:
        sys.exit(f"unexpected file {path.name}")
    groups.setdefault((m.group(1), m.group(2)), []).append(path)
if not groups:
    sys.exit("no step rvmats found")

for (body, color), paths in groups.items():
    template = paths[0].read_text()
    if len(EMISSIVE.findall(template)) != 1:
        sys.exit(f"{paths[0].name}: expected exactly one emmisive line")
    for path in paths:
        path.unlink()
    for step, mult in enumerate(MULTIPLIERS, start=1):
        (bodies / f"{body}_{color}_{step}.rvmat").write_text(EMISSIVE.sub(emissive(color, mult), template))
print(f"{len(groups)} materials -> {len(groups) * len(MULTIPLIERS)} files")

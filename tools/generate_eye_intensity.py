"""Builds the 5 eye brightness steps for every per-body glow material.

DayZ can't change emissive at runtime, so each brightness step is its own rvmat.
Source files are data/bodies/<body>_<color>.rvmat (step 3); this writes
data/bodies/<body>_<color>_<step>.rvmat with only the emmisive[] line changed.
"""
import pathlib, re, sys

STEPS = {
    1: {"yellow": "1.25,1.0,0,1", "red": "1.5,0.05,0,1", "blue": "0.1,0.35,1.5,1", "green": "0.15,1.25,0.05,1", "orange": "1.5,0.6,0,1"},
    2: {"yellow": "1.75,1.4,0,1", "red": "2.1,0.07,0,1", "blue": "0.14,0.49,2.1,1", "green": "0.21,1.75,0.07,1", "orange": "2.1,0.84,0,1"},
    3: {"yellow": "2.5,2.0,0,1", "red": "3.0,0.1,0,1", "blue": "0.2,0.7,3.0,1", "green": "0.3,2.5,0.1,1", "orange": "3.0,1.2,0,1"},
    4: {"yellow": "3.25,2.6,0,1", "red": "3.9,0.13,0,1", "blue": "0.26,0.91,3.9,1", "green": "0.39,3.25,0.13,1", "orange": "3.9,1.56,0,1"},
    5: {"yellow": "4.0,3.2,0,1", "red": "4.8,0.16,0,1", "blue": "0.32,1.12,4.8,1", "green": "0.48,4.0,0.16,1", "orange": "4.8,1.92,0,1"},
}
EMISSIVE = re.compile(r"emmisive\[\]\s*=\s*\{[^}]*\};")

bodies = pathlib.Path(__file__).resolve().parent.parent / "data" / "bodies"
sources = [p for p in bodies.glob("*.rvmat") if not re.search(r"_\d\.rvmat$", p.name)]
if not sources:
    sys.exit("no source rvmats found")
for src in sources:
    color = src.stem.rsplit("_", 1)[1]
    text = src.read_text()
    if len(EMISSIVE.findall(text)) != 1:
        sys.exit(f"{src.name}: expected exactly one emmisive line")
    for step, values in STEPS.items():
        out = EMISSIVE.sub(f"emmisive[]={{{values[color]}}};", text)
        src.with_name(f"{src.stem}_{step}.rvmat").write_text(out)
    src.unlink()
print(f"{len(sources)} materials -> {len(sources) * len(STEPS)} files")

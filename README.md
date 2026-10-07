# The Original Glowing Zombie Eyes 2.0

Inspired by the glowing eyes of Call of Duty Zombies. Give DayZ's infected glowing eyes in five colors, and control every one of them from an in-game admin menu. No XML editing, no map setup, and it works on any map.

## What's new in 2.0

- **In-game admin menu**: choose vanilla or glowing eyes for every zombie type, live, while you play.
- **Five glow colors**: yellow, red, blue, green and orange.
- **Brightness slider (1 to 10)**: from a subtle glint to blinding.
- **Per-body glow materials**: each zombie keeps its own vanilla skin, cloth and shading detail; only the eyes glow.
- **Works on any map**: eyes are applied as zombies spawn, so Chernarus, Livonia, Sakhal and custom maps all work with their normal spawns.
- **Saved permanently**: settings survive server restarts.
- **Eyes stay visible**: glowing zombies never spawn with hats, helmets, masks or glasses covering their faces.

## Installation

1. Add the mod to **both your server and your clients**. It is required on both, because the menu and the glow materials live client-side.
2. Add the server key from the mod's Keys folder to your server's keys folder.
3. Start the server once. It creates `DZNC_Zombies/Admins.json` inside your server's profile folder.

## Making yourself an admin

Open `<server profile folder>/DZNC_Zombies/Admins.json` and add your Steam64 ID (the 17-digit number from your Steam profile URL or a site like steamid.io):

```json
{
    "SteamIDs": [
        "76561198000000000"
    ],
    "DebugLineup": false
}
```

Add more admins by separating IDs with commas. Restart the server after editing; the file is read at startup.

`DebugLineup` is for testing: set it to `true` and the first admin to join after a restart gets one of every zombie type spawned in front of them, frozen, so you can compare colors side by side. Leave it `false` on a live server.

## Using the menu

Press **End** in game to open the Zombie Eyes menu (rebind "Zombie Eye Admin Menu" in your Controls settings). Players who are not on the admin list just get a "not on the admin list" message.

- **Zombie list**: all 145 vanilla zombie types with their current eye color. Search by name, or filter to glowing only.
- **Per zombie**: pick Vanilla or Glowing and choose the color. **Apply to all outfits** copies the setting to every outfit of that body.
- **All zombies at once**: set every zombie to one color, **Randomize all colors**, or **Reset all to vanilla** (click twice to confirm).
- **Eye brightness**: one slider for every glowing zombie, 1 (dim) to 10 (super bright), 5 is normal.
- **Live preview**: the selected zombie appears in front of you, frozen. Click and drag outside the menu to spin it. Drag the red header to move the menu.

Every change applies instantly to zombies already in the world and is saved to `DZNC_Zombies/EyeSettings.json` in the server profile folder.

## Good to know

- A fresh install starts with every zombie on vanilla eyes. Open the menu and set your colors (or hit Randomize all colors) to get the glow going.
- The glow shows best at night. Brightness 8 and above adds a soft halo around the eyes; 9 and 10 are deliberately extreme.
- Zombies added by other mods are left untouched.
- The pre-colored DZNC zombie classes from 1.0 still work and now follow the menu settings of their vanilla type.

## Looking for the original?

Version 1.0 is still available if you prefer the classic setup with its pre-colored zombie classes: [Glowing Zombie Eyes 1.0](https://steamcommunity.com/sharedfiles/filedetails/?id=2466713208)

## Can I repack it?

No, and you shouldn't need to. Everything is configured in game and saved on your server, so there is nothing to unpack or edit.

## Source code

The source is available through our Discord. Come say hi and you can get access there.

## Support

Need help? Find us on Discord: [discord.gg/dayznchill](https://discord.gg/dayznchill)

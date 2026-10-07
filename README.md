# The Original Glowing Zombie Eyes 2.0

Inspired by the glowing eyes of Call of Duty Zombies. Give DayZ's infected glowing eyes in every color of the rainbow, and control every one of them from an in-game admin menu. No XML editing, no map setup, and it works on any map.

## What's new in 2.0
- **In-game admin menu**: choose vanilla or glowing eyes for every zombie type, live, while you play.
- **Full ROYGBIV spectrum**: red, orange, yellow, green, blue, indigo and violet.
- **Brightness slider (1 to 10)**: from a subtle glint to blinding.
- **Crazy eyes**: every zombie's eyes cycle rapidly through the whole rainbow.
- **Fade on death**: glowing eyes slowly fade out after a kill.
- **Every zombie covered**: all vanilla infected, including the Sakhal winter zombies, soldiers, Navy and the 1.30 additions, detected automatically.
- **Per-body glow materials**: each zombie keeps its own vanilla skin, cloth and shading detail; only the eyes glow.
- **Works on any map**: eyes are applied as zombies spawn. Tested on Chernarus, Livonia, Sakhal, Deer Isle, Melkart and Esseker, on DayZ 1.29 and 1.30 experimental.
- **Saved permanently**: settings survive server restarts.

## Installation
- Subscribe and add the mod to **both your server and your clients** (it is required on both, because the menu and the glow materials live client-side).
- Add the server key from the mod's Keys folder to your server's keys folder.
- Start the server once. It creates **DZNC_Zombies/Admins.json** inside your server's profile folder.

## Making yourself an admin
Open **`<server profile folder>`/DZNC_Zombies/Admins.json** and add your Steam64 ID (the 17-digit number from your Steam profile URL or a site like steamid.io):

```json
{
    "SteamIDs": [
        "76561198000000000"
    ],
    "DebugLineup": false
}
```

Add more admins by separating IDs with commas. Restart the server after editing; the file is read at startup.

**DebugLineup** is for testing: set it to true and the first admin to join after a restart gets one of every zombie type lined up in front of them, so you can compare colors. While it's on, glowing zombies also skip hats, masks and glasses so their eyes are easy to see. Leave it false on a live server.

## Using the menu
Press **End** in game to open the Zombie Eyes menu. You can rebind it under Controls in the **DZNC** tab. Players who are not on the admin list just get a "not on the admin list" message.
- **Zombie list**: every zombie type with its current eye color. Search by name, or switch between All zombies and Glowing only.
- **Selected zombie**: pick a color and that zombie glows; choose Vanilla to turn it off. **Apply to all outfits** copies the setting to every outfit of that body.
- **All zombies**: set every zombie to one color, **Randomize colors**, or **Reset to vanilla** (click twice to confirm).
- **Crazy eyes** and **Fade eyes on death**: switch them on or off for the whole server.
- **Eye brightness**: one slider for every glowing zombie, 1 (dim) to 10 (super bright), 5 is normal.
- **Live preview**: the selected zombie appears in front of you, standing still. Click and drag outside the menu to spin it, and drag the header to move the menu.
Every change applies instantly to zombies already in the world and is saved to **DZNC_Zombies/EyeSettings.json** in the server profile folder.

## Good to know
- A fresh install starts with every zombie on vanilla eyes. Open the menu and set your colors (or hit Randomize colors) to get the glow going.
- The glow shows best at night. Brightness 8 and above adds a soft halo around the eyes; 9 and 10 are deliberately extreme.
- Zombies added by other mods with their own models or skins are left untouched.
- The Mummy, NBC suit zombies and the new 1.30 female soldiers keep vanilla eyes.
- The pre-colored DZNC zombie classes from 1.0 still work and now follow the menu settings of their vanilla type.

## Looking for the original?
Version 1.0 is still available if you prefer the classic setup with its pre-colored zombie classes: [Glowing Zombie Eyes 1.0](https://steamcommunity.com/sharedfiles/filedetails/?id=2466713208)

## Can I repack it?
No, and you shouldn't need to. Everything is configured in game and saved on your server, so there is nothing to unpack or edit. If you'd like to view the source, come say hi on our Discord and you can get access there.

## Source code

The source is available through our Discord. Come say hi and you can get access there.

## Support
Need help? Find us on Discord: [discord.gg/dayznchill](https://discord.gg/dayznchill)

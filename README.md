

# WT32 Clock
A demo clock project for WT32 board with heads-up notification display.

### Companion App
Chronos

<a href='https://play.google.com/store/apps/details?id=com.fbiego.chronos&pcampaignid=pcampaignidMKT-Other-global-all-co-prtnr-py-PartBadge-Mar2515-1'><img alt='Get it on Google Play' height="100px" src='https://play.google.com/intl/en_us/badges/static/images/badges/en_badge_web_generic.png'/></a>

## wt32-lvgl-template

This is a template project for WT32-SC01 board for LVGL UI development.

You can compile this project as is without the UI files. Do this to ensure you have the correct display and lvgl settings.

Default build environment is `wt32-sc01-plus`

### SquareLine Studio

[`Download Link`](https://squareline.io/)

With SquareLine studio you can create ui using drag and drop. The source code can be exported for use on the hardware.

#### Create a project

- Don't use `-` in the project name
- Resolution `320 480` for portrait or `480 320` for landscape
- Color depth `16 bit swap`

#### Exporting the UI

- Export the UI files from SquareLine to [`src/ui/`](https://github.com/fbiego/wt32-lvgl-template/tree/master/src/ui) folder
- In `include/main.h`, uncomment the line `// #define USE_UI` to use the exported UI files
- In `src/ui/ui.h`, change `#include "lvgl/lvgl.h"` to `#include "lvgl.h"`
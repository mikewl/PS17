# Atlantis PS17 Macropad

![Atlantis PS17](https://i.imgur.com/Y0rkPgA.jpg)

A 17-key macro pad with pushbutton rotary encoder and underglow RGB per key RGB and for the case.

* Keyboard Maintainer: solartempest
* Hardware Supported: Atlantis PS17 v2
* Hardware Availability: [rioo897](https://shop198276076.world.taobao.com/index.htm?spm=2013.1.w5002-23418336364.2.3f4d7d51DkVX3s)

# Custom Features:

-   Remappable rotary encoder controls volume up/down/mute.
-   Adds key combo functionality for backspace, delete, and arrow keys.
-   RGB underglow and matrix support and remapped to physical locations (nicer gradient and effects).
-   Adds custom layer lighting with custom gradients (if enabled) for each.
-   VIA support included by default.
-   Allows for remapping of per-layer rotary encoder functions in VIA.
-   Custom macro key in VIA for Super Alt Tab, which is fully compatible with rotary encoders.
-   Custom macro key in VIA for moving windows to other monitors in Windows, which is fully compatible with rotary encoders.

## Make and Flashing

Make example for this keyboard (after setting up your build environment):

    make solartempest/ps17:via

To reset the board into bootloader mode, tap the Reset switch mounted on the bottom of the PCB.
Flash with QMK toolbox, auto-flash.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

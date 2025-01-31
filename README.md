[![OG Demo](https://github.com/aladshaw3/FreeRTOS/actions/workflows/original_SIL_demo.yml/badge.svg)](https://github.com/aladshaw3/FreeRTOS/actions/workflows/original_SIL_demo.yml)
[![SIL Blinky Demo](https://github.com/aladshaw3/FreeRTOS/actions/workflows/blinky_demo.yml/badge.svg)](https://github.com/aladshaw3/FreeRTOS/actions/workflows/blinky_demo.yml)
[![SIL WIN Demo](https://github.com/aladshaw3/FreeRTOS/actions/workflows/win_blinky_demo.yml/badge.svg)](https://github.com/aladshaw3/FreeRTOS/actions/workflows/win_blinky_demo.yml)
[![QEMU Demo](https://github.com/aladshaw3/FreeRTOS/actions/workflows/CORTEX_M3_Emulation.yml/badge.svg)](https://github.com/aladshaw3/FreeRTOS/actions/workflows/CORTEX_M3_Emulation.yml)

### NOTICE ###
This is a clone of `FreeRTOS` pinned to Tag `V10.4.1` that has now diverged from the original source project.
The purpose of this divergence is that this specific version of `FreeRTOS` actually has a working `FreeRTOS/Demo/Posix_GCC` build on Linux. Current versions of this demo, from the original source, are broken.

The remainder of this `README` has updated the instructions specifically for this diverged fork of the project.


## Getting started
The easiest way to use FreeRTOS is to start with one of the pre-configured demo application projects (found in the FreeRTOS/Demo directory).  That way you will have the correct FreeRTOS source files included, and the correct include paths configured.  Once a demo application is building and executing you can remove the demo application files, and start to add in your own application source files.  See the [FreeRTOS Kernel Quick Start Guide](https://www.freertos.org/FreeRTOS-quick-start-guide.html) for detailed instructions and other useful links.

Additionally, for FreeRTOS kernel feature information refer to the [Developer Documentation](https://www.freertos.org/features.html), and [API Reference](https://www.freertos.org/a00106.html).

### Getting help
If you have any questions or need assistance troubleshooting your FreeRTOS project, we have an active community that can help on the [FreeRTOS Community Support Forum](https://forums.freertos.org). Please also refer to [FAQ](http://www.freertos.org/FAQHelp.html) for frequently asked questions.

## Cloning this repository
This repo uses [Git Submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) to bring in dependent components.

Using SSH:
```
git clone git@github.com:aladshaw3/FreeRTOS.git --recurse-submodules
```

If you have downloaded the repo without using the `--recurse-submodules` argument, you need to run:
```
git submodule update --init --recursive
```

## Repository structure
This repository contains the FreeRTOS Kernel, a number of supplementary libraries, and a comprehensive set of example applications.

### Kernel sources
The FreeRTOS Kernel Source is in [FreeRTOS/FreeRTOS-Kernel repository](https://github.com/FreeRTOS/FreeRTOS-Kernel), and it is consumed as a submodule in this repository.

The version of the FreeRTOS Kernel Source in use could be accessed at ```./FreeRTOS/Source``` directory.

A number of Demo projects can be found under ```./FreeRTOS/Demo``` directory.

### Supplementary library sources
The [FreeRTOS-Plus/Source](https://github.com/FreeRTOS/FreeRTOS/tree/master/FreeRTOS-Plus/Source) directory contains source code for some of the FreeRTOS+ components, as well as select partner provided libraries. These subdirectories contain further readme files and links to documentation.

[FreeRTOS-Labs](https://github.com/FreeRTOS/FreeRTOS/tree/master/FreeRTOS-Labs) contains libraries and demos that are fully functional, but undergoing optimizations or refactorization to improve memory usage, modularity,
documentation, demo usability, or test coverage.  At this time the projects ARE A WORK IN PROGRESS and will be released in the main FreeRTOS directories of the download following full review and completion of the documentation.

## Other releases of the Original Source Project
Other releases are available for download under [releases](https://github.com/FreeRTOS/FreeRTOS/releases).

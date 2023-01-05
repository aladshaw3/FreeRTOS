# Running in Linux

## Requirements ##

1. Install `qemu` tool chains.

```
sudo apt-get install qemu
sudo apt install qemu-system-arm
```

2. Install `gcc` for specific device

```
sudo apt install gcc-arm-none-eabi
```

**NOTE**: Other toolchains and compilers may need to be installed for
different use cases, hardware, and microprocessors. Use `sudo apt install qemu-system-*` to
get the appropriate virtualization box and `sudo apt install gcc-*` for the compilers.

## Build and Run ##

1. Go to the `build/gcc` directory and use `make`

```
cd build/gcc
make
```

**NOTE**: This should create an `RTOSDemo.out` image file in `output`

2. Run the image file through the virtualization tool

```
qemu-system-arm -machine mps2-an385 -cpu cortex-m3 -kernel output/RTOSDemo.out -monitor none -nographic -serial stdio
```

**NOTE**: Demo will run infinitely. To stop, you must kill the process by typing `ctrl+c`.

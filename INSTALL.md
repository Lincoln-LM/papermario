# Setup

This repository supports:

- [Linux](#unix)
- [macOS](#unix)
- [Windows Subsystem for Linux 2](#wsl-2)
- [Docker](#docker) (any host OS)
- [Nix](#nix)

If you encounter any issues setting up the repo, please feel free to [reach out to us on Discord](https://discord.gg/urUm3VG).

## Common

Clone the repository:
```sh
git clone https://github.com/pmret/papermario
cd papermario
```

## Unix

Install build dependencies:
```sh
./install.sh
```

> **NOTE:** On Mac, if you get an error that looks like
>
>```sh
>Error: Cannot install md5sha1sum because conflicting formulae are installed.
>  coreutils: because both install `md5sum` and `sha1sum` binaries
>
>Please `brew unlink coreutils` before continuing.
>```
>
>it's fine to just open `install.sh` in a text editor, delete the `md5sha1sum` from the `brew install` line, and rerun it (put it back after so you don't accidentally commit it!)

Copy baseroms into the following places (at least 1 is required):

* `ver/us/baserom.z64` (sha1: `3837f44cda784b466c9a2d99df70d77c322b97a0`)
* `ver/jp/baserom.z64` (sha1: `b9cca3ff260b9ff427d981626b82f96de73586d3`)

(If you're using WSL, you can enter the Linux filesystem by opening `\\wsl$` in File Explorer; e.g. `\\wsl$\Ubuntu\home\<your username>\papermario`.)

Configure the build and extract assets from the base ROM:
```sh
./configure
```

Compile the game:
```
ninja
```

If you get `papermario.z64: OK` at the end, the build succeeded!

The output ROM is `papermario.z64` - you can run this in any N64 emulator.


## WSL 2

1. Install or upgrade to **WSL 2** following [these instructions](https://aka.ms/wsl2-install) (Ubuntu is recommended)
2. Open a WSL terminal
3. Run the following command: `sudo apt update && sudo apt upgrade && cd ~`
4. Continue with [the instructions for Linux](#unix)

If you have Visual Studio Code, you can type `code .` to open the repo within it.
`Ctrl + J` opens up a Linux terminal within VS Code.


## Docker

A Docker image containing all dependencies can be built and ran as follows:
```sh
docker build . -t pm
docker run --rm -ti -v $(pwd):/papermario pm
```

Then continue with [the instructions for Linux](#unix), but you can skip the install.sh!

## Nix

Install [Nix](https://nixos.org/download.html) and run `nix-shell`. You will need to set the `NIXPKGS_ALLOW_UNSUPPORTED_SYSTEM` environment variable to `1` (required for cross compiling).

```sh
export NIXPKGS_ALLOW_UNSUPPORTED_SYSTEM=1
nix-shell
```

Like the instructions for Docker, continue with [the instructions for Linux](#unix), but you can skip the install.sh!

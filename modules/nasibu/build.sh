#!/bin/sh

# run cargo build
cargo build -Z build-std-features="compiler-builtins-softfloat"  -Z build-std="core,alloc,compiler_builtins" --target=target.json



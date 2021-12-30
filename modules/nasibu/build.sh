#!/bin/sh

# run cargo build
cargo build -Z build-std=core,alloc --target=target.json



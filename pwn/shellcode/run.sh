#!/bin/sh
socat -v tcp-l:10004,reuseaddr,fork exec:"./shellcode"

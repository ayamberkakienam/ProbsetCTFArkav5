#!/bin/sh
socat -v tcp-l:10002,reuseaddr,fork exec:"./echo"

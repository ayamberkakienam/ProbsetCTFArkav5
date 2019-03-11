#!/bin/sh
socat -v tcp-l:31002,reuseaddr,fork exec:"python ./server.py"

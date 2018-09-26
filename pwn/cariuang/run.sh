#!/bin/sh
socat -v tcp-l:1234,reuseaddr,fork exec:'./cariuang'
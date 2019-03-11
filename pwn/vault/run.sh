#!/bin/sh
socat -v tcp-l:31003,reuseaddr,fork exec:"./vault"

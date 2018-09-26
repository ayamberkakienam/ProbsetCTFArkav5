#!/bin/sh
socat -v tcp-l:13337,reuseaddr,fork exec:'./hangman'

#!/bin/bash
if [[ ! -f bank ]]; then
	echo 'error: compile this exercise before attempting the diff.'
	exit 1
fi

LOG=bank.log

./bank > "$LOG"
git diff -U0 --word-diff --no-index -- 19920104_091532.log "$LOG"
rm "$LOG"

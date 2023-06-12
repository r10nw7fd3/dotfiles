#!/bin/sh

while true; do
	xsetroot -name " \"$(wpa_cli status | grep -E "^ssid=" | cut -d = -f 2)\" $(date +'%d.%m.%Y %H:%M') $(pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}' | tr -d '\n') $(cat /sys/class/power_supply/BAT1/capacity)% "
	sleep 1
done

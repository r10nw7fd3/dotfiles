#!/bin/sh

while true; do
	wpa_state=$(wpa_cli status) | grep wpa_state=COMPLETED
	if [ "$(wpa_cli status | grep wpa_state=COMPLETED)" = "wpa_state=COMPLETED" ]; then
		wpa_state="+"
	else
		wpa_state="-"
	fi
	date=$(date +"%d.%m.%Y %H:%M")
	volume=$(pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}' | tr -d '\n')
	bat_cap=$(cat /sys/class/power_supply/BAT1/capacity)%
	xsetroot -name " $wpa_state $date $volume $bat_cap "
	sleep 1
done

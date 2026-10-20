ifconfig -a | grep -E "ether" | tr -s " " | cut -d ' ' -f 3

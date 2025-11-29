#!/bin/bash
echo "Логін та ID групи користувачів (перші 10):"
awk -F: '{print "User:", $1, "| Group ID:", $4}' /etc/passwd | head -n 10

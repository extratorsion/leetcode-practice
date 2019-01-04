cat file.txt | egrep '(^[[:digit:]]{3}-|^\([0-9]{3}\) )[[:digit:]]{3}-[[:digit:]]{4}$'

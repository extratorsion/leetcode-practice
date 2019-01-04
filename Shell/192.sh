cat words.txt | tr " " "\n" | sed "/^$/d" | sort | uniq -c | sort -k2 -nr | awk '{print $2 " " $1}'

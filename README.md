# makewords
makewords *NIX program

Inspired by this video:
https://www.youtube.com/watch?v=tc4ROCJYbm0

Usage:

````bash
cat test.txt | makewords | sort 
````

Sample russian dictionary maker bash script:

````bash
#!/bin/bash
echo "This is sample script  to use makewords program to generate dictionary from online books"
wget -O ./tmp.txt http://lib.ru/RUFANT/ABRANOW/selesta.txt
cat ./tmp.txt | iconv -f KOI8-R -t UTF-8 | makewords -l | sort | uniq -u | sort > ./dict.txt
rm ./tmp.txt
````

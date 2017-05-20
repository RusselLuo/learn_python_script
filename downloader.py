from bs4 import BeautifulSoup
import requests
import re

r = requests.get('http://cn163.net/archives/23794/')
bsObj = BeautifulSoup(r.text, 'lxml')
name = []
for i in range(1, 23):
    num = str(i)
    if i < 10:
        num = '0' + num
    name.append('第' + num + '集.WEB-1024.mp4')
link = bsObj.find_all(name='a', text=name)

for i in link:
    print(i['href'])

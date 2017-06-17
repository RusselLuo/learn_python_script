from bs4 import BeautifulSoup
import requests
import re


#site = input('please enter the address: ')
#keyword = input('please enter the keyword to search: ')
r = requests.get('http://cn163.net/archives/23811/')
bsObj = BeautifulSoup(r.text, 'lxml')
name = []
for i in range(1, 23):
    num = str(i)
    if i < 10:
        num = '0' + num
    name.append('第' + num + '集.HD1024.mp4')
link = bsObj.find_all(name='a', text=name)

for i in link:
    print(i['href'])

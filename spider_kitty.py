from bs4 import BeautifulSoup
from bs4 import UnicodeDammit
import requests
import re


def get_content(key):
    '''receive a string as argument, return a response object'''
    home_page = 'https://www.torrentkitty.tv/search/'
    r = requests.get(home_page + key + '/')
    r.encoding = 'utf-8'
    return r


key = input('Please enter the key word to search: ')
file_name = input('Please enter the file name of result: ')
end = False
while end == False:
    try:
        mode = int(input("1: text & magnet link\n2: just magnet link: "))
        end = True
    except:
        print('You entered a wrong number')
        pass
r = get_content(key)
if r.status_code == 200:
    print('Successfully get the result')
    bsObj = BeautifulSoup(r.text, 'lxml')
    result = bsObj.find_all('a', href=re.compile('magnet'))
    f = open(file_name + '.txt', mode='w')
    with f:
        for i in result:
            if mode == 1:
                f.write(i['title'] + ' :\n')
            f.write(i['href'] + '\n')
else:
    print('Something happen: ' + str(r.status_code))

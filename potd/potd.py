import urllib
import time
from bs4 import BeautifulSoup
import re
import seleniumrequests
import os
from sign_in import login_module


def getNewUrl(bsObj, url):
    action = bsObj.find("form")['action']
    index = url.find("/idp")
    newUrl = url[0:index] + action
    return newUrl


def get_reletive_url(response, keyWord):
    bsObj = BeautifulSoup(response.text, "lxml")
    newUrl = bsObj.find(href=re.compile(keyWord))['href']
    return newUrl


prarielearn = "https://prairielearn.engr.illinois.edu"
s = seleniumrequests.PhantomJS()
r = s.get('https://prairielearn.engr.illinois.edu/pl')

# username = input("Your username: ")
# password = input("Your password: ")
# data = {'j_username': 'chuchao2',
# 'j_password': 'aB19661969', '_eventId_proceed': 'Login'}

login_info = login_module(prarielearn, 'chuchao2', 'aB19661969')
login_info.uiuc_login(s)

table = s.find_element_by_tag_name('table')
potd_url = table.find_element_by_tag_name('a')
potd_url.click()
tbody = s.find_element_by_tag_name('tbody')
potd_url = tbody.find_element_by_tag_name('a')
potd_url.click()
table = s.find_element_by_tag_name('table')
tbody = table.find_element_by_tag_name('tbody')
potd_url = tbody.find_element_by_tag_name('a')
potd_url.click()
time.sleep(5)

s.save_screenshot(time.ctime() + '.png')
bsObj = BeautifulSoup(s.page_source, 'lxml')
url = prarielearn + bsObj.find(href=re.compile('instance_question'))['href']
f = open('abc.sh', 'wb')
f.write(s.request('GET', url).content)
f.close()
print('file downloaded')
os.system('sh abc.sh')
os.system('rm abc.sh')
s.close()
#
#
# bs_pra = BeautifulSoup(login.text, "lxml")
# pra_url = bs_pra.find('form')['action']
# RelayState = bs_pra.find('input', {'name': 'RelayState'})['value']
# SAMLResponse = bs_pra.find('input', {'name': 'SAMLResponse'})['value']
#
#
# data2 = {'RelayState': RelayState, 'SAMLResponse': SAMLResponse}
# header2 = {'Connection': 'keep-alive',
#            'Host': 'prairielearn.engr.illinois.edu',
#            'Origin': 'https://shibboleth.illinois.edu',
#            'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
#            'Referer': newUrl,
#            'Accept-Encoding': 'gzip, deflate, br',
#            'Cache-Control': 'max-age=0',
#            'Content-Length': '64',
#            'Content-Type': 'application/x-www-form-urlencoded',
#            'Upgrade-Insecure-Requests': '1',
#            'Accept-Language': 'zh-CN,zh;q=0.8',
#            'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36'}
# login = s.request('POST',pra_url, data=data2)  # without header

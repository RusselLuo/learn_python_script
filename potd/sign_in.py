import urllib
import time
from bs4 import BeautifulSoup
import re
import seleniumrequests
import os
import requests


class login_module:
    __main_url = ''
    __username = ''
    __password = ''

    def __init__(self, main_url, username, password):
        self.__username = username
        self.__password = password
        self.__main_url = main_url

    def uiuc_login(self, broser):
        username = broser.find_element_by_id('j_username')
        username.send_keys(self.__username)
        password = broser.find_element_by_id('j_password')
        password.send_keys(self.__password)
        submit = broser.find_element_by_name('_eventId_proceed')
        submit.click()

    def Enterprise_login(self):
        s = requests.Session()
        header = {'Referer': 'https://eas.admin.uillinois.edu/eas/servlet/EasLogin?redirect=https://webprod.admin.uillinois.edu/ssa/servlet/SelfServiceLogin?appName=edu.uillinois.aits.SelfServiceLogin&dad=BANPROD1',
                  'Host': 'eas.admin.uillinois.edu', 'Origin': 'https://eas.admin.uillinois.edu'}
        data = {'inputEnterpriseId': self.__username,
                'password': self.__password, 'BTN_LOGIN': 'Login', "queryString": 'null'}
        r = s.post(self.__main_url, data=data, headers=header)
        print(r.text)
        return s

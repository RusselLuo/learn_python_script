from sign_in import login_module
import requests
from bs4 import BeautifulSoup

login_info = login_module(
    'https://eas.admin.uillinois.edu/eas/servlet/login.do', 'chuchao2', 'aB19661969')
s = login_info.Enterprise_login()
r = s.get("https://ui2web1.apps.uillinois.edu/BANPROD1/twbkwbis.P_GenMenu?name=bmenu.P_StuMainMnu")
print(r.text)

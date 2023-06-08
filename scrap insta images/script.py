import os
import sys

import requests as rq
from bs4 import BeautifulSoup

def get_content(url):
    return rq.get(str(url))

def get_beautify(res):
    return BeautifulSoup(res, 'html.parser')

def get_img_links(soup):
    img_urls = []
    for url in soup.find_all('img'):
        src = url.attrs['src']
        if 'data:image/png;base64' in src:
            pass
        else:
            img_urls.append(src)

    return img_urls

def download_images(urls, path, user):
    path = path + "\\insta_images\\"
    i = 0; os.system(f'mkdir {path}\\{user}')
    for url in urls:
        try:
            with open(path + user + f'\\img{i}.jpeg', 'wb') as fp:
                fp.write(get_content(url).content); i = i + 1
        except Exception as error:
            sys.exit(error)

def read_content(path):
    with open(path + '/html.txt', encoding="utf8") as fp:
        content = fp.read()
    return content

def extract_info(soup):
    user = soup.title.string.split(' ')
    if '@' in user[2]:
        user = user[2]
    else:
        user = user[1]
    return str(user)
    
    
if __name__ == '__main__':
    os.system('mkdir insta_images')
    
    if os.path.exists(str(sys.argv[1])) == True:
        content = read_content(str(sys.argv[1]))
        soup = get_beautify(content)
        urls = get_img_links(soup);
        user = extract_info(soup)
        download_images(urls, os.getcwd(), user)
    else:
        res = get_content(sys.argv[1])
        soup = get_beautify(res.content)
        urls = get_img_links(soup)
        download_images(urls, os.getcwd())

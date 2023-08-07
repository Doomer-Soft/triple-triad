
import requests 
import os
from bs4 import BeautifulSoup 
from pprint import pprint


  
url = 'https://vgkami.com/final-fantasy-viii-triple-triad-cards-list/' 

def imagedown(url,folder):
    try:
        os.mkdir(os.path.join(os.getcwd(), folder))
    except:
        pass

    os.chdir(os.path.join(os.getcwd(), folder))
    r = requests.get(url)

    soup = BeautifulSoup(r.text, 'html.parser')
    table = soup.find('div', class_="post-content")
    images = table.find_all('img')
    
    for image in images:
        name = image['alt'].replace(" ", "-")
        print(name)
        link = image['src']
        with open(name + '.jpg', 'wb') as f:
            im = requests.get(link)
            f.write(im.content)

imagedown(url, 'cards')
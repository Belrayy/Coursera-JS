import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
import ssl

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

def follow_links(start_url, count, position):
    current_url = start_url
    for _ in range(count):
        print(f"Retrieving: {current_url}")
        html = urllib.request.urlopen(current_url, context=ctx).read()
        soup = BeautifulSoup(html, 'html.parser')
        
        tags = soup('a')
        if len(tags) < position:
            print("Error: Not enough links on the page.")
            return None
        
        # Get the link at the specified position
        tag = tags[position - 1]
        current_url = tag.get('href', None)
    
    return current_url

start_url = input('Enter URL: ')
count = int(input('Enter count: '))
position = int(input('Enter position: '))

last_url = follow_links(start_url, count, position)

if last_url:
    last_name = last_url.split('_')[-1].split('.')[0]
    print(f"The last name in the sequence is: {last_name}")
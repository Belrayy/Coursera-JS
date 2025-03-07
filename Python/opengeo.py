import urllib.request, urllib.parse
import json, ssl

serviceurl = 'https://py4e-data.dr-chuck.net/opengeo?'

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

address = input('Enter location: ')
if len(address) < 1:
    address = 'South Federal University'  

parms = dict()
parms['q'] = address
url = serviceurl + urllib.parse.urlencode(parms)

print('Retrieving', url)
uh = urllib.request.urlopen(url, context=ctx)
data = uh.read().decode()
print('Retrieved', len(data), 'characters')

try:
    js = json.loads(data)
except:
    js = None

if not js or 'features' not in js or len(js['features']) == 0:
    print('==== Error retrieving data ====')
    print(data)
else:
    plus_code = js['features'][0]['properties'].get('plus_code')
    if plus_code:
        print('Plus code:', plus_code)
    else:
        print('Plus code not found in the response.')
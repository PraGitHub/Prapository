Problem statement : find the best and worst possible cases in time for Mr.X in logging in to his account successfully<br/>
Given : <br/>
Mr.X will always try to enter passwords in non-decreasing order of their lengths<br/>
For 'K' consecutive unsuccessful tries => time = 5 s<br/>
For every try => time = 1 s<br/>
<br/>
Inputs<br/>
N K<br/>
password1<br/>
password2<br/>
.<br/>
.<br/>
.<br/>
passwordN<br/>
password<br/>
<br/>
Inputs Explaination => first line will have N and K <br/>
Next 'N' lines will have all passwords<br />
'N+1'th line will have actual password<br />
It is for sure that the actual password will be in one of the first 'N' lines<br />
<br />
Example : <br />
<br />
Inputs :<br />
10 2<br />
apple<br />
orange<br />
banana<br />
mango<br />
gkgkgk<br />
rose<br />
jasmine<br />
hibiscus<br />
marigold<br />
prashanth<br />
gkgkgk<br />
<br />
Output :<br />
8<br />
14<br />
<br />
Explaination :<br />
Best Case : rose apple mango gkgkgk<br />
1 5 1 1 = 8<br />
Worst Case : rose apple mango banana orange gkgkgk<br />
1 5 1 5 1 1 = 14<br />


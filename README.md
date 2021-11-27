# FinalIntegralActivity 

<p>
This is the final project of the data structures course. We are intended to implement
a cpp application that analyses some log data files from a server. The data represents
failed logs to some platform. The application reads the file selected by setting the
name and location of the file on the command promp. Each failed log contains the
following data:
</p>
<ul>
  <li>Moth : 3 letters format.</li>
  <li>Day  : dd format.</li>
  <li>Hour : hh:mm:ss format.</li>
  <li>IP   : ###.###.###.###:##### with port number.</li>
  <li>Status: description of failure.</li>
</ul>

**Example** : "*Jul 13 07:17:09 149.9.162.86:6876 Failed password for illegal user root*"


![alt text](https://github.com/H3cth0r/FinalIntegralActivity/blob/main/resources/data_file_example.JPG)



The folloging URL is the source of the logs: **https://drive.google.com/drive/folders/1vtSvYAaiLdU9BsvNyFniEvDAO3pYzyI3?usp=sharing**


From this files and data, we shall get the following data and cover the following points:

<ul>
  <li>Five directions with more illegal breaches.</li>
  <li>Frequency of each error message.</li>
  <li>Count of attacked ports.</li>
  <li>Dates where there were more illegal breaches(per week).</li>
</ul>
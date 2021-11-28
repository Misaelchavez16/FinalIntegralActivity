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


![file structure example](https://github.com/H3cth0r/FinalIntegralActivity/blob/main/resources/data_file_example.JPG)



The folloging URL is the source of the logs: **https://drive.google.com/drive/folders/1vtSvYAaiLdU9BsvNyFniEvDAO3pYzyI3?usp=sharing**


From this files and data, we shall get the following data and cover the following points:

<ul>
  <li>Five directions with more illegal breaches.</li>
  <li>Frequency of each error message.</li>
  <li>Count of attacked ports.</li>
  <li>Dates where there were more illegal breaches(per week).</li>
</ul>

It was instructed that a basic requierent for the development, we whould apply four differente data structures.
An we must also stablish the time complexity for each used method.

## Ussage
In the following section, is presented the way to run the code for getting the correspondent
results or wanted data. First of all, the code should be compiled for it to work. Remember
that this is a "set in command promp parameters" based program, so the instruction should be
written on the command promp before running the .exe. It is also totally necessary store the logs in the same place the main file is located. The following parameters or commands
are available to be runned:
<ul>
  <li>-h or --help       :   to acces ussage parameters or comments.</li>
  <li>-f or --file       :   for setting the route and name of the file.</li>
  <li>-d or --directions :   command to get the most breached directions. Input number of directions to be retrieved.</li>
  <li>--frequency        :   returns the frequency of each message.</li>
  <li>-a or --attacked   :   returns number of attacked ports.</li>
  <li>--dates            :   returns days wiht more breaches per week.</li>
</ul>


**Example** : "*main.exe -f route/fileName.txt -d 5 --frequency -a -d*"
![execution example](https://github.com/H3cth0r/FinalIntegralActivity/blob/main/resources/code_runned.JPG)

## About the logic on the development of each method from the points to be covered
<ul>
  <li>Input parameters on command promp: this method was used for checking which commands were inputted on command promp. We would add the commands to a queue, because this way it is easier to dequeue the commands from the queue and each time some command comes out from the list, it will be runned. the parameters like route or number of ips to get out from the files are stored on a variable each, this way the commands were separated from the route or number. </li>
  <li>Five directions with more illegal breaches: for this method, we made use of a Hastable, Linkedlist and stack. The Linkedlist is passed as parameter, and the Hastable is passed as a referenced parameter. The Hastable was used for storing the key, which is the ip and as value it was stored an integer. when iterating the Linked list with the data of each log, if there was an occurrence of the ip, it was added on the Hashtable.
  Then we made use of the stack for iterating the hastable and get the ips with more occurrences. We used some queue's methods, as FIFO data entry. </li>
  <li>Frequency of each error message: hastable with each message as a key.When there is an ocurranse, the integer stored at each key should be added a one.From there it is easier to get the values that repeated the most. We iterate the linked list with the logs, each time there was an ocurrance we added to Hastable key value.
  </li>
  <li>Count of attacked ports: create a Hastable of ports. When there is a new key, not previously recorded at hastable, it will be added to hashtable and to an Stack. We used the hastable for indexing the value, because its complexity for indexing and looking for
  a value is very fast. At the end we get the size of the stack and now we have the number of attacked ports and an actual linked list with the values.
  </li>
  <li>Dates where there were more illegal breaches(per week): we created a vector containing the abreviatons of months of the year, for later comparation wiht logs. As we know that the year has 53 weaks, we created a Hastable of that size; when some day and month was detected, it was addend an integer to value of some number of week. At the end we just iterate the Hastable and we check in which months there were more breaches; we would input this weeks into a Linkedlist, because it could happen that there ara some weeks with the same number of breaches.</li>
</ul>

## Used data structures
<ul>
  <li>Stack</li>
  <li>Queue</li>
  <li>Linked list</li>
  <li>Hashtable</li>
  <li>Vectors</li>
</ul>

## Credits
Héctor Miranda García-A01658845

Humberto Alejandro Rosas Téllez-A01659823

Isabel Cristina Valdés Luevanos-A01025802

Misael Chavez Ramos-A01659759
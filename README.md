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
  <li>Five directions with more illegal breaches: we use a hashtable where each key is an ip direction in string format. When there is a new occurence, the integer value of the key is updated by adding the ocurrance. We use container class, where we store the ip and number of ocurrance, for then inserting values to linked list and sorting them for getting the one with more occurrences.</li>
  <li>Frequency of each error message: hastable with each message as a key.When there is an ocurranse, the integer stored at each key should be added a one.From there it is easier to get the values that repeated the most.
  </li>
  <li>Count of attacked ports: create a Hastable of ports. When there is a new key, not previously recorded at hastable, it will be added to hashtable and to an Stack. We used the hastable for indexing the value, because its complexity for indexing and looking for
  a value is very fast. At the end we get the size of the stack and now we have the number of attacked ports and an actual linked list with the values.
  </li>
  <li>Dates where there were more illegal breaches(per week): for this point, we used a hastble, where each key is a week. We calculate the week number depending of the date and if there is an occurenc, we sum the integer value and then we exporte it to a linkedlist
  for getting the the one with the hihest number of occurence, by using deques_max method.</li>
</ul>

## Used data structures
<ul>
  <li>Stack</li>
  <li>Queue</li>
  <li>Linked list</li>
  <li>Hastable</li>
</ul>
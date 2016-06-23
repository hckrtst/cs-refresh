#Problem
Design and algorithm to remove duplicate chars in a string. You may not
use any complicated large data structures. Some local variables are ok.

#Notes
##Constraints and Assumptions
* can't use any other buffers
* assuming ascii chars
* assuming that space is not duplicate


##Examples
input = "An apple a day"
output="An aple dy"

* Since we can't use any other data structures we would need multiple iterations


#Pseudocode

for each char c in string str
   substr = get_sub_str(index+1)
   find_and_delete(substr, c)

#Postmortem
* Always handle null and empty strings!


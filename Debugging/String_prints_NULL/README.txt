Objective:
==========
  Whats wrong in this program.


Logic:
=======
  In main, we are passing the pointer. In mystrcpy function, we are over-riding those pointer values by using an malloc.
  But this value is not reflected at all in main function. 

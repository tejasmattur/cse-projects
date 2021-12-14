In order to declare an interface in C++, it's necessary to make a class with pure virtual methods and a destructor. The interface can then be used 
by creating other classes that override the previously made virtual methods.

We created the test file object with name "test file". using cout and .read(), we tested each of our methods to see if they worked
as expected. They did, as our write ended up read() ing the vector we used in write. After, we append() ed and read() from there and the
new read had included the append. As a final check, we ran getSize() and getName() and cout'ed it to verify that those functions also worked.


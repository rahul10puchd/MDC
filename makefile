mdc : main.o  compression.o decompression.o decompression2.o decompression3.o decompression4.o decompression5.o decompression6.o decompression7.o createarray.o unique.o insert.o operation1.o mainmenu.o codelength.o compression2.o compression3.o  compression4.o compression5.o compression6.o compression7.o preserve_masterarray.o findloc.o
	gcc -o mdc main.o compression.o decompression.o decompression2.o decompression3.o decompression4.o decompression5.o decompression6.o decompression7.o createarray.o unique.o insert.o operation1.o mainmenu.o codelength.o compression2.o compression3.o compression4.o compression5.o compression6.o compression7.o preserve_masterarray.o findloc.o
main.o : main.c header.h prototype.h 
	gcc -c main.c
compression.o : compression.c header.h prototype.h
	gcc -c compression.c
decompression.o : decompression.c header.h prototype.h
	gcc -c decompression.c
decompression2.o : decompression2.c header.h prototype.h
	gcc -c decompression2.c
decompression3.o : decompression3.c header.h prototype.h
	gcc -c decompression3.c
decompression4.o : decompression4.c header.h prototype.h
	gcc -c decompression4.c
decompression5.o : decompression5.c header.h prototype.h
	gcc -c decompression5.c
decompression6.o : decompression6.c header.h prototype.h
	gcc -c decompression6.c
decompression7.o : decompression7.c header.h prototype.h
	gcc -c decompression7.c
createarray.o : createarray.c header.h prototype.h
	gcc -c createarray.c
unique.o : unique.c header.h prototype.h
	gcc -c unique.c
insert.o : insert.c header.h prototype.h
	gcc -c insert.c
operation1.o : operation1.c header.h prototype.h
	gcc -c operation1.c
mainmenu.o : mainmenu.c header.h prototype.h
	gcc -c mainmenu.c 
compression2.o: compression2.c header.h prototype.h
	gcc -c compression2.c
compression3.o : compression3.c header.h prototype.h
	gcc -c compression3.c
compression4.o: compression4.c header.h prototype.h
	gcc -c compression4.c
compression5.o : compression5.c header.h prototype.h
	gcc -c compression5.c
compression6.o: compression6.c header.h prototype.h
	gcc -c compression6.c
compression7.o : compression7.c header.h prototype.h
	gcc -c compression7.c
codelength.o : codelength.c header.h prototype.h
	gcc -c codelength.c
preserve_masterarray : preserve_masterarray.c header.h prototype.h
	gcc -c preserve_masterarray.c 
findloc : findloc.c header.h prototype.h
	gcc -c findloc.c
	

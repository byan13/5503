# CS550Assignment3
## Name: Bo Yan

-----------------------------------------------------------------------
-----------------------------------------------------------------------

## Description:
Files provided:

    track_fault.c
    Makefile
    
Usage of Makefile:

    sudo make
        This will create
            track_fault.ko along with all other files
    sudo make clean
        This will remove all files except the file track_fault.c
        
Usage of track_fault.ko:
    
    sudo insmod track_fault.ko pid=<pid parameter>
        note <pid parameter> is the process id to be passed
    sudo rmmod track_fault.ko
    
Exception handling:

    All system call exceptions catched will print the perror messages.
    Other exceptions catched will print the custom error messages.
        
Reference:

    https://www.kernel.org/doc/Documentation/kprobes.txt
    https://elixir.bootlin.com/linux/latest/source/samples/kprobes
    https://elixir.bootlin.com/linux/latest/source/mm/memory.c#L4191yes
    

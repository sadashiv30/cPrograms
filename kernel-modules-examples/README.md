
Kernel Modules: Refer http://www.tldp.org/LDP/lkmpg/2.6/html/lkmpg.html 

lsmod : List all the modules 
insmod hello-5.ko : install a .ko kernel module into the kernel
rmmod hello-3 : remove the installed module
modinfo hello-1 : Print the information of a installed module
dmesg | tail  : To see the kernel messages

Working:
KM always begin with either the init_module or the function you specify with module_init call.
All modules end by calling either cleanup_module or the function you specify with the module_exit call.



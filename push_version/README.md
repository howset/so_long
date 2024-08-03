Difference:
- this version is tested on the cluster, the graphics stays after minimize, so the line with expose (on run_mlx) is not necessary. This line introduces leaks with the current termination method I have anyway.
- the norminette version is different, so the header files does not contain tile defines anymore, instead the functions address this directly ('1', 'P', etc).

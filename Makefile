DEPENDENDENT_DIRS = Image Util Ray GL
DEPENDENDENT_MAKEFILES = Makefile1

all:
	for dir in $(DEPENDENDENT_DIRS); do make -C $$dir; done
	for makefile in $(DEPENDENDENT_MAKEFILES); do make -f $$makefile; done

debug:
	for dir in $(DEPENDENDENT_DIRS); do make debug -C $$dir; done
	for makefile in $(DEPENDENDENT_MAKEFILES); do make -f $$makefile; done

clean:
	for dir in $(DEPENDENDENT_DIRS); do make clean -C $$dir; done
	for makefile in $(DEPENDENDENT_MAKEFILES); do make clean -f $$makefile; done

depend:
	for dir in $(DEPENDENDENT_DIRS); do make depend -C $$dir; done
	for makefile in $(DEPENDENDENT_MAKEFILES); do make depend -f $$makefile; done

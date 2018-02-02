

DIRS = src crypto db 

all:
	@for dir in ${DIRS}; do make -C $$dir -j4; echo ; done


clean:
	@for dir in ${DIRS}; do make -C $$dir clean; echo ; done


type_test:
	@echo ${OS_NAME};



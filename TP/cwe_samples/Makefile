# Creative Commons Attribution-ShareAlike 3.0 License -
# This work is licensed under the Creative Commons Attribution-Share Alike
# 3.0 License. To view a copy of this license,
# visit http://creativecommons.org/licenses/by-sa/3.0/legalcode;
# or, (b) send a letter to Creative Commons, 171 2nd Street, Suite 300, San
# Francisco, California, 94105, USA.
#
# Originally created : Mataru
#
DIR="cwe_120"
DIR+="cwe_131"
DIR+="cwe_134"
DIR+="cwe_190"
DIR+="cwe_798"
DIR+="cwe_807"

.PHONY: all build clean mrproper subdirs $(SUBDIRS)

all: build

build:
	for dir in $(DIR); do		\
		$(MAKE) -C "$$dir";	\
	done

clean:
	for dir in $(DIR); do                   \
                $(MAKE) clean -C "$$dir";       \
        done

mrproper:
	for dir in $(DIR); do                   \
                $(MAKE) mrproper -C "$$dir";    \
	done

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

#
# Makefile targets to remake configuration
#

freshconf: Makefile

Makefile: $(srcdir)/Makefile.in $(top_srcdir)/configure.in
	cd $(top_prjdir) && $(SHELL) ./config.status

# End of conf.mk

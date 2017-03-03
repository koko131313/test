#
#    test - test of the test
#
#    Copyright (c) the Authors
#

# To build with draft APIs, use "--with drafts" in rpmbuild for local builds or add
#   Macros:
#   %_with_drafts 1
# at the BOTTOM of the OBS prjconf
%bcond_with drafts
%if %{with drafts}
%define DRAFTS yes
%else
%define DRAFTS no
%endif
Name:           test
Version:        0.1.0
Release:        1
Summary:        test of the test
License:        GPL-2.0+
URL:            https://test.com/
Source0:        %{name}-%{version}.tar.gz
Group:          System/Libraries
# Note: ghostscript is required by graphviz which is required by
#       asciidoc. On Fedora 24 the ghostscript dependencies cannot
#       be resolved automatically. Thus add working dependency here!
BuildRequires:  ghostscript
BuildRequires:  asciidoc
BuildRequires:  automake
BuildRequires:  autoconf
BuildRequires:  libtool
BuildRequires:  pkgconfig
BuildRequires:  systemd-devel
BuildRequires:  systemd
%{?systemd_requires}
BuildRequires:  xmlto
BuildRequires:  zeromq-devel
BuildRequires:  czmq-devel
BuildRequires:  malamute-devel
BuildRoot:      %{_tmppath}/%{name}-%{version}-build

%description
test test of the test.

%package -n libtest0
Group:          System/Libraries
Summary:        test of the test shared library

%description -n libtest0
This package contains shared library for test: test of the test

%post -n libtest0 -p /sbin/ldconfig
%postun -n libtest0 -p /sbin/ldconfig

%files -n libtest0
%defattr(-,root,root)
%{_libdir}/libtest.so.*

%package devel
Summary:        test of the test
Group:          System/Libraries
Requires:       libtest0 = %{version}
Requires:       zeromq-devel
Requires:       czmq-devel
Requires:       malamute-devel

%description devel
test of the test development tools
This package contains development files for test: test of the test

%files devel
%defattr(-,root,root)
%{_includedir}/*
%{_libdir}/libtest.so
%{_libdir}/pkgconfig/libtest.pc
%{_mandir}/man3/*
%{_mandir}/man7/*

%prep
%setup -q

%build
sh autogen.sh
%{configure} --enable-drafts=%{DRAFTS} --with-systemd-units
make %{_smp_mflags}

%install
make install DESTDIR=%{buildroot} %{?_smp_mflags}

# remove static libraries
find %{buildroot} -name '*.a' | xargs rm -f
find %{buildroot} -name '*.la' | xargs rm -f

%files
%defattr(-,root,root)
%doc README.md
%{_bindir}/test-main
%{_mandir}/man1/test-main*
%config(noreplace) %{_sysconfdir}/test/test-main.cfg
/usr/lib/systemd/system/test-main.service
%dir %{_sysconfdir}/test
%if 0%{?suse_version} > 1315
%post
%systemd_post test-main.service
%preun
%systemd_preun test-main.service
%postun
%systemd_postun_with_restart test-main.service
%endif

%changelog

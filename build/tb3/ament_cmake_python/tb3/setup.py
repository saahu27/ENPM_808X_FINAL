from setuptools import find_packages
from setuptools import setup

setup(
    name='tb3',
    version='0.0.0',
    packages=find_packages(
        include=('tb3', 'tb3.*')),
)

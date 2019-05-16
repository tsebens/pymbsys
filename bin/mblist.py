"""
Provides pythonic access to an MB file.

Interface that allows the user to execute the commands of MB-System on the specified file. Each of those commands is
provided as a python method of this object, and will allow the user to specify the appropriate flags for that command.
Each command will also provide default configurations for that command.


Currently only implements the mblist function  -TS 15/MAY/19
"""
import os.path
import subprocess as sp


def gmt5_bin_dir():
    # todo: Figure out a way to dynamically look up where the gmt5 lib is
    return r'C:\Users\tristan.sebens\Projects\pymbsys\gmt5\bin'


class MBFile:
    def __init__(self, fp):
        # todo: If there is some file extension that happens to have 'mb' in it, behaviour is undefined. Make better
        # (.mbw)     – MBRWizard archive
        # (.emb)     – Wilcom ES Designer Embroidery CAD file
        # (.mbp)     - metadata for Mobipocket documents
        # (.mb)      - Autodesk Maya Binary File
        # (.embl)    - The flatfile format used by the EMBL to represent database records
        # (.numbers) - An Apple Numbers Spreadsheet file
        # (.ftmb)    - Family Tree Maker backup file

        exts = fp.split('.')
        if not any(['mb' in e for e in exts]):
            raise TypeError('Specified file is not an MB System file.')

        self._fp = fp # Path to the specified file
        self._format = int(list(filter(lambda e: 'mb' in e, exts[::-1]))[0].replace('mb', ''))

    def list(self, o_fp):
        """Extract the data from the file"""
        # Build the command
        cmd = "mblist -I {input_fp} -X {output_fp} -G , -MA".format(**{'input_fp': self._fp, 'output_fp': o_fp})
        # Execute the command
        sp.run(os.path.join(gmt5_bin_dir(), cmd))
        return o_fp


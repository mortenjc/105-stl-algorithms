#!/usr/local/bin/python3

import os
import graphviz


class Draw:

    def __init__(self, filename, vector, names=[], bold=[]):
        self.filename = filename
        self.vector = vector
        self.names = names
        self.bold = bold

        if names == []:
            self.names = [str(val) for val in vector]
        assert len(self.names) == len(self.vector)

        self.g = graphviz.Graph(format='png')
        self.g.engine = 'dot'
        self.g.attr( 'node', margin='0', fontsize='24',
                     color='black', shape='circle', width='0.5'
            #style='filled',
            #fontcolor='white',
        )
        self.g.attr('edge', color='grey', penwidth='0.75')


    def get_name(self, idx):
        if len(self.names) != 0:
            return self.names[idx]
        else:
            return str(idx)


    def node_attr(self, **kwargs):
        self.g.attr('node', **kwargs)


    def edge_attr(self, **kwargs):
        self.g.attr('edge', **kwargs)


    def draw(self):
        for i, _ in enumerate(self.vector):
            n = i + 1
            name = self.get_name(i)

            if int(name) in self.bold:
                self.g.node(name,  margin='0', fontsize='24',
                            color='grey', shape='circle', width='0.5',
                            style='filled', line='black') #, fontcolor='white'
            else:
                self.g.node(name, margin='0', fontsize='24',
                         color='black', shape='circle', width='0.5')


        for i, v in enumerate(self.vector):
            n = i + 1
            l = n * 2
            r = n * 2 + 1

            vname = self.get_name(n-1)
            if l - 1 < len(self.vector):
                wname = self.get_name(l-1)
                self.g.edge(vname, wname, color='black', penwidth='1.0')
            if r - 1 < len(self.vector):
                wname = self.get_name(r-1)
                self.g.edge(vname, wname, color='black', penwidth='1.0')

        self.g.render(filename=f"imgs/{self.filename}.dot")
        os.rename(f"imgs/{self.filename}.dot.png", f"imgs/{self.filename}.png")

if __name__ == '__main__':

    initialise = [
        [[3, 2, 4, 1, 5, 9], [5, 4, 9]],
        [[3, 2, 9, 1, 5, 4], [5, 9]],
        [[9, 2, 3, 1, 5, 4], [5, 4]],
        [[9, 2, 4, 1, 5, 3], [5]],
        [[9, 5, 4, 1, 2, 3], []]
    ]

    construct = [
        [[3], []],
        [[3, 2], []],
        [[3, 2, 4], [4]],
        [[4, 2, 3], []],
        [[4, 2, 3, 1], []],
        [[4, 2, 3, 1, 5], [5]],
        [[4, 5, 3, 1, 2], [5]],
        [[5, 4, 3, 1, 2], []],
        [[5, 4, 3, 1, 2, 9], [9]],
        [[5, 4, 9, 1, 2, 3], [9]],
        [[9, 4, 5, 1, 2, 3], []]
    ]


    for i, data in enumerate(initialise):
        vec = data[0]
        bold = data[1]
        d = Draw(f"heap_init{i+1}", vec, [], bold)
        d.draw()

    for i, data in enumerate(construct):
        vec = data[0]
        bold = data[1]
        d = Draw(f"heap_push{i+1}", vec, [], bold)
        d.draw()

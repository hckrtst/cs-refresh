class Node:
    def __init__(self, label=None):
        if not label is None:
            self.label = label
        else:
            self.label = self
        print("Created node %s" % self.label)
        self.data = None
        self.next = None

    def setData(self, d):
        self.data = d

    def getData(self):
        return self.data

    def setNext(self, n):
        self.next = n

    def getNext(self):
        return self.next


'''
Quick and dirty tests
'''
import unittest
class NodeTest(unittest.TestCase):
    def setUp(self):
        self.n1 = Node("flash")
        self.n1.setData(10)
        self.n2 = Node("arrow")
        self.n2.setData(23)

    def test1_node_data(self):
        print("Testing data")
        self.assertEqual(self.n1.getData(), 10)
        self.assertEqual(self.n2.getData(), 23)

    def test2_linking(self):
        print("Testing linking")
        self.n1.setNext(self.n2)
        self.assertEqual(self.n1.getNext(), self.n2)

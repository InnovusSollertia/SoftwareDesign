import networkx as nx
import matplotlib.pyplot as plt

def make_simple_graph():
    G = nx.DiGraph()
    G.add_nodes_from([1, 2, 3, 4, 5])

    edges = [(1, 2), (1, 3), (2, 3), (3, 4), (3, 5)]
    G.add_edges_from(edges)
    return G

def draw_graph(graph):
    pos = nx.spring_layout(graph)
    nx.draw(graph, pos, with_labels=True, node_size=700, node_color="skyblue", font_size=8, font_color="black", font_weight="bold", arrowsize=10, connectionstyle="arc3,rad=0.1")
    plt.show()

simple_graph = make_simple_graph()
draw_graph(simple_graph)
import math
import scipy

def create_closedSet(self):
    """ Creates and returns a data structure suitable to hold the set of nodes already evaluated"""
    # EXAMPLE: return a data structure suitable to hold the set of nodes already evaluated
    return set()

def create_openSet(self):
    """ Creates and returns a data structure suitable to hold the set of currently discovered nodes
    that are not evaluated yet. Initially, only the start node is known."""
    if self.start != None:
        # return a data structure suitable to hold the set of currently discovered nodes
        #  that are not evaluated yet. Make sure to include the start node.
        self.openSet = set()
        self.openSet.add(self.start)
        return self.openSet
    raise(ValueError, "Must create start node before creating an open set. Try running PathPlanner.set_start(start_node)")

def create_cameFrom(self):
    """Creates and returns a data structure that shows which node can most efficiently be reached from another,
    for each node."""
    #  return a data structure that shows which node can most efficiently be reached from another,
    #  for each node.
    self.cameFrom = {}
    return self.cameFrom

def create_gScore(self):
    """Creates and returns a data structure that holds the cost of getting from the start node to that node,
    for each node. The cost of going from start to start is zero."""
    #   return a data structure that holds the cost of getting from the start node to that node, for each node.
    # for each node. The cost of going from start to start is zero. The rest of the node's values should
    # be set to infinity.
    self.gScore = {}
    for i in range(len(self.map.intersections)):
        self.gScore[i] = float('inf')
    self.gScore[self.start] = 0
    return self.gScore

def create_fScore(self):
    """Creates and returns a data structure that holds the total cost of getting from the start node to the goal
    by passing by that node, for each node. That value is partly known, partly heuristic.
    For the first node, that value is completely heuristic."""
    #  return a data structure that holds the total cost of getting from the start node to the goal
    # by passing by that node, for each node. That value is partly known, partly heuristic.
    # For the first node, that value is completely heuristic. The rest of the node's value should be
    # set to infinity.
    self.fScore = {}
    for i in range(len(self.map.intersections)):
        self.fScore[i] = float('inf')
    self.fScore[self.start] = self.distance(self.start, self.goal)

    return self.fScore

def set_map(self, M):
    """Method used to set map attribute """
    self._reset(self)
    self.start = None
    self.goal = None
    #  Set map to new value.
    self.map = M

def set_start(self, start):
    """Method used to set start attribute """
    self._reset(self)
    #  Set start value. Remember to remove goal, closedSet, openSet, cameFrom, gScore, fScore,
    # and path attributes' values.
    self.goal = None
    self.closedSet = None
    self. openSet = None
    self.cameFrom = None
    self.gScore = None
    self.fScore = None
    self.path = None
    self.start = start
    return self.start

def set_goal(self, goal):
    """Method used to set goal attribute """
    self._reset(self)
    #  Set goal value.
    self.goal = goal
    return self.goal

def is_open_empty(self):
    """returns True if the open set is empty. False otherwise. """
    #  Return True if the open set is empty. False otherwise.
    return not bool(self.openSet)

def get_current_node(self):
    """ Returns the node in the open set with the lowest value of f(node)."""
    #  Return the node in the open set with the lowest value of f(node).
    return min(self.openSet, key = self.calculate_fscore)

def get_neighbors(self, node):
    """Returns the neighbors of a node"""
    #  Return the neighbors of a node
    return self.map.roads[node]

def get_gScore(self, node):
    """Returns the g Score of a node"""
    #  Return the g Score of a node
    return self.gScore[node]

def distance(self, node_1, node_2):
    """ Computes the Euclidean L2 Distance"""
    # Compute and return the Euclidean L2 Distance
    return scipy.spatial.distance.euclidean(self.map.intersections[node_1],
                                            self.map.intersections[node_2])


def get_tentative_gScore(self, current, neighbor):
    """Returns the tentative g Score of a node"""
    # Return the g Score of the current node
    # plus distance from the current node to it's neighbors
    return self.gScore[current] + self.distance(current, neighbor)

def heuristic_cost_estimate(self, node):
    """ Returns the heuristic cost estimate of a node """
    # Return the heuristic cost estimate of a node
    return self.distance(node, self.goal)

def calculate_fscore(self, node):
    """Calculate the f score of a node. """
    # Calculate and returns the f score of a node.
    # REMEMBER F = G + H
    return self.gScore[node] + self.heuristic_cost_estimate(node)

def record_best_path_to(self, current, neighbor):
    """Record the best path to a node """
    # Record the best path to a node, by updating cameFrom, gScore, and fScore
    self.cameFrom[neighbor] = current
    self.gScore[neighbor] = self.get_tentative_gScore(current, neighbor)
    self.fScore[neighbor] = self.calculate_fscore(current)





